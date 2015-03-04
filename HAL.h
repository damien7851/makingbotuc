/**
 *  \file HAL.h
 *  \brief fichier d'entête de la couche d'abstraction matériel
 */
#ifndef HAL_H
#define HAL_H 
#include <stdlib.h>
#include "include/globletypedef.h"
#include "include/mapping.h"
#define READ false
#define WRITE true
// definition of datatype length
#define PINGLENGHT 0
#define GPIOBITLENGTH 2
#define GPIOPORTLENGTH 2
#define CURRENTCHANNEL 2
#endif //a bouger en fin de fichier


/******************************************
 *  définition des type enuméré
 */
 
 // /brief type de data 
typedef enum eDataType
	{
		PING = 0x0, //longueur data 0
		GPIOBIT = 0x1, //longueur data 2 1er octect numéro gpio, 2eme etat gpio type bool
		GPIOPORT = 0x2, // numéro du port suivi data la dir est fixé dans le code
		CURRENTCHANNEL = 0x3, //voie courant suivie de la valeur
		NONE = 0xFF
	}eDataType;

// /brief type de port
typedef enum ePortType
	{
		I2CSLAVE,
		I2CMASTER,
		FULLDUPLEX
	}tPortType;
	
typedef enum eParity
	{
		EVEN,
		ODD,
		NONE
	}tParity;

typedef enum eStatus	
{
BUSY,
IDLE,
CLOSED,
ERROR
}tStatus;

/****************
 *  définition des structures en mémoire
 */
// /brief structure des données en mémoire 
static typedef struct sData
	{
		uchar id,  //identifiant du device
		bool rw,	//action sur le device vaut TRUE en ecriture
		eDataType Datatype,
		uchar * Data,
	}tData;
static typedef struct sPort
{
tdata data,
uchar num, //identifiant unique du port voir si utile
tStatus statu
}tPort;


// /brief strutuire des paramétre de port
typedef struct sParam
	{
		uchar bauds, //vitesse du port
		tParity parity, //parité du port
		uchar start, // nombre de bit de start 
		uchar stop,
	}tParam;

/**
 *  \brief fonction d'initialisation et de création de port
 *  
 *  \param [in] porttype type de port à ouvrir 
 *  \param [in] PortNum numéro du port à ouvrir
 *  \param [in] param liste des paramétre du port
 *  \return renvoie un pointeur sur les données du port
 *  
 *  \details Details
 */
 tPort* initCom(const tPortType porttype,const uchar PortNum,const tParam param);

 /**
 *  \brief ferme le port
 *  
 *  \param [in] tdata pointeur vers les donnes du port
 *  \return rien
 *  
 *  \details Details
 */
 void closeCom(port tPort);
 
 /**
 *  \brief récuopére les données du port
 *  
 *  \param [in] port pointeur sur le port
 *  \return pointeur sur les données
 *  
 *  \details Details
 */
 uchar* getData(const *tPort port);
 
 /**
 *  \brief set data on port
 *  
 *  \param [in] port pointer on port
 *  \return status of port
 *  
 *  \details Details
 */tStatus setData(const *tPort port);
 /**
 *  \brief renvoie la longueur de la donnée
 *  
 *  \param [in] port pointeur sur le port
 *  \return longueur des donnees
 *  
 *  \details Details
 */
 uint getDataLength(const *tPort port);
 
 /**
 *  \brief renvoi le statu du port
 *  
 *  \param [in] port pointeur sur le port
 *  \return statu
 *  
 *  \details Details
 */
 tStatus getStatus(const *tPort port);
 
/**
 *  \brief return unique id for a new port
 *  
 *  \return Return_Description
 *  
 *  \details Details
 */
 uchar newNumCom();
 
 /**
 *  \brief return unique id of port
 *  
 *  \param [in] port pointer on port
 *  \return unique id
 *  
 *  \details Details
 */
 uchar numCom(const *tport port);