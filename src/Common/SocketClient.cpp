/* ---------------------------------------------------------------------------*/
/* Includes                                                                   */
/* ---------------------------------------------------------------------------*/
#include <unistd.h>
#include "SocketClient.h"
#include "Utilities.h"

/* ---------------------------------------------------------------------------*/
/* Debug                                                                      */
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
/* Defines, Estructuras y Typedef                                             */
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
/* Declaracion de funciones                                                   */
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/* Variables externas y privadas                                              */
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/* Implementacion de clases y funciones                                       */
/* ---------------------------------------------------------------------------*/


SocketClient::SocketClient(UniqueDeviceId_t server, ProcessReciveData_t processReciveData)
{
    /* Defino nombre de Server */
    char sat1ServerName[] = "../../Satelite/main/SAT1_SERVER";
    char sat2ServerName[] = "../../Satelite/main/SAT2_SERVER";
    char* serverName;
    if (server == SATELITE_1_ID)
    {
        serverName = sat1ServerName;
    }
    else
    {
        serverName = sat2ServerName;
    }
    DEBUG_MSG("serverName: " << serverName << std::endl);

    /* Inicializacion de Socket */
    memset((char *)&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, serverName);
    servlen = strlen( serv_addr.sun_path) + sizeof(serv_addr.sun_family);

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    connect(sockfd, (struct sockaddr *)&serv_addr, servlen);

    /* Handler de recepcion */
    m_processReciveData = processReciveData;

    DEBUG_MSG("CLIENT INIT" << std::endl);
}

SocketClient::~SocketClient()
{

}

void SocketClient::sendData(CommunicationsBuffer_t* data)
{

}

void SocketClient::runnerTask(void)
{
    /* Vaciar buffer de transmision*/
    // n = write( newsockfd, "Obtuve su mensaje", 18 );

    memset( buffer, '\0', MAX_BUFFER_SIZE );
    /* Leer y procesar buffer de recepcion */
    n = read( sockfd, buffer, MAX_BUFFER_SIZE - 1 );
    // processReciveData()
}

void SocketClient::processReciveData(CommunicationsBuffer_t* data)
{

}

/*----------------------------------------------------------------------------*/
/* Fin                                                                        */
/*----------------------------------------------------------------------------*/