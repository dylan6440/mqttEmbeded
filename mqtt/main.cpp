#include <QCoreApplication>
#include <mqtt/client.h>
#include <ostream>
using namespace std;

typedef char        char_t;
typedef float       float32_t;      /*!< float32_t: float.          Ex: f32_var*/
typedef double      float64_t;      /*!< float64_t: double.         Ex: f64_var*/
typedef long double float92_t;      /*!< float92_t: long double.    Ex: f92_var*/
typedef int			int32_t;        /*!< int32_t : int.             Ex: s32_var: */
typedef unsigned int uint32_t;      /*!< uint32_t : unsigned int.   Ex: u32_vat: */

int main(int argc, char *argv[])
{
    // Define an address pointing to a broker
    string s_IpAddress = "broker.emqx.io:1883";
    // Define an ID to be used by the client
    string s_IdClient = "Dylan.Orto";
    // Define an Topic
    string s_Topic = "/ynov/bordeaux/";

    // Create client with IP Adress ans ID Client
    mqtt::client ClientYnov(s_IpAddress, s_IdClient);

    // Option connection
    mqtt::connect_options Options;
    // set_keep_alive_interval is the maximum time that should pass without communications
    Options.set_keep_alive_interval((20));
    // Sets whether the server should remember state for the client across reconnects.
    Options.set_clean_session(true);

    try {
        // Connect with options
        ClientYnov.connect(Options);

        for (int32_t s32_var = 0; s32_var < 3; ++s32_var) {
            string s_Message = "Ca marche enfin !! je suis un mec incroyable !";
            mqtt::message_ptr mqtt_Message = mqtt::make_message(s_Topic, s_Message);
            //mqtt_Message->
            ClientYnov.publish((mqtt_Message));
        }
        ClientYnov.disconnect();

    } catch (const mqtt::exception& exc) {
        cerr<<exc.what()<<endl;
        return 1;
    }

    QCoreApplication a(argc, argv);

    return a.exec();
}
