#include <QCoreApplication>
#include <mqtt/client.h>
#include <iostream>
using namespace std;

typedef char        char_t;
typedef float       float32_t;      /*!< float32_t: float.          Ex: f32_var*/
typedef double      float64_t;      /*!< float64_t: double.         Ex: f64_var*/
typedef long double float92_t;      /*!< float92_t: long double.    Ex: f92_var*/
typedef int			int32_t;        /*!< int32_t : int.             Ex: s32_var: */
typedef unsigned int uint32_t;      /*!< uint32_t : unsigned int.   Ex: u32_vat: */

// Define an address pointing to a broker
string s_IpAddress = "broker.emqx.io:1883";
// Define an ID to be used by the client
string s_IdClient = "Dylan.Orto.reader";
// Define an Topic
string s_Topic = "/ynov/bordeaux/";

// Create client with IP Adress ans ID Client
mqtt::client ClientYnov(s_IpAddress, s_IdClient);

class mqtt_callback : public virtual mqtt::callback
{
public:

    virtual void connection_lost(const std::string& s_Cause)
    {
        cerr << "Connection lost: "<< s_Cause << endl;
    }

    virtual void message_arrived (mqtt::const_message_ptr msg_ptr)
    {
        if (msg_ptr->get_qos() == 0) // Verification du 005
        {
            if(msg_ptr->get_topic() == s_Topic) // Vérification du topic
            {
                cout << "Received message: " << msg_ptr->to_string() << endl;
            }
        }

    }

    virtual void delivery_complete (mqtt::delivery_token_ptr token)
    {
        cout << "Delivery complete for token: " << token->get_message_id() << endl;
    }

};

int main(int argc, char *argv[])
{
     // Option connection
    mqtt::connect_options Options;
    // set_keep_alive_interval is the maximum time that should pass without communications
    Options.set_keep_alive_interval((20));
    // Sets whether the server should remember state for the client across reconnects.
    Options.set_clean_session(true);

    mqtt_callback Callback;
    ClientYnov.set_callback(Callback);


    try {
        // Connect with options
        ClientYnov.connect(Options);
        ClientYnov.subscribe(s_Topic, 0);
        while (true) {}
        ClientYnov.disconnect();

    } catch (const mqtt::exception& exc) {
        cerr<<exc.what()<<endl;
        return 1;
    }

    QCoreApplication a(argc, argv);

    return a.exec();
}
