/**
 *  \file HAL.c
 *  \brief implémantation de la couche d'abstraction matérielle
 *  \details Details
 */

#include "include/HAL.h"





tPort* initCom(const tPortType porttype,const uchar PortNum,const tParam param)
{
tPort* port = malloc(sizeof(tPort));
port.statu = IDLE;
port.num = newNumCom();
port.data.id = PortNum;
port.data.rw = READ;
port.data.DataType = NONE;
port.data.Data = malloc(1); //on aloue 1 octet par defaut
switch(porttype)
{
case I2CSLAVE :
initComI2CSlave(portNum); //general call always activated
break;
case default:
break;
}
return 0; //erreur??
}



 /**
 *  \brief ferme le port
 *  
 *  \param [in] tdata pointeur vers les donnes du port
 *  \return rien
 *  
 *  \details Details
 */
 void closeCom(port *tdata)
 {
 }
 
 /**
 *  \brief récuopére les données du port
 *  
 *  \param [in] port pointeur sur le port
 *  \return pointeur sur les données
 *  
 *  \details Details
 */
 uchar* getData(const *tdata port)
 {
 return 0; //erreur???
 }
 
 /**
 *  \brief set data on port
 *  
 *  \param [in] port pointer on port
 *  \return status of port
 *  
 *  \details Details
 */tStatus setData(const *tdata port)
 {
 return 0;
 }
 /**
 *  \brief renvoie la longueur de la donnée
 *  
 *  \param [in] port pointeur sur le port
 *  \return longueur des donnees
 *  
 *  \details Details
 */
 uint getDataLength(const *tdata port)
 {
 return 0;
 }
 
 /**
 *  \brief renvoi le statu du port
 *  
 *  \param [in] port pointeur sur le port
 *  \return statu
 *  
 *  \details Details
 */
 tStatus getStatus(const *tdata port)
 {
 return 0;
 }
 
 /**
 *  \brief return unique id for a new port
 *  
 *  \return unique id
 *  
 *  \details limited to 254 device from 1 to 254 return 0 if fail
 */
 uchar newNumCom()
 {
 static uchar id = 0;
 if (id==255)
	id = 0;
 else 
	id++;
 return id;
 }
 
 /**
 *  \brief give num of port
 *  
 *  \param [in] port pointer to port
 *  \return num port
 *  
 *  \details Details
 */uchar numCom(tPort* port)
 {
 return port->num;
 }
 