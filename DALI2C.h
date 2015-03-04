 /**
 *  \file DALI2C.h
 *  \brief wrapper beetween HAL and atmel I2C driver
 */
 
 #ifndef DALI2C_H
 #define DALI2C_H
 #include "include/TWI_slave.h"
 #include "include/HAL.h"
 #endif //a bouger en fin de fichier
 
 
 void ();
 
  /**
 *  \brief Open I2C port
 *  
 *  
 *  \return Status of port
 *  
 *  \details Details
 */
 tStatus initComI2CSlave(uchar);

 /**
 *  \brief close port
 *  
 *  
 *  \return nothing
 *
 *  
 *  \details disable interruption interuption 
 */
 void closeComI2CSlave();
 
 /**
 *  \brief get data on port
 *  
 *  
 *  \return pointer on data
 *  
 *  \details Details
 */
 uchar* getDataI2CSlave();
 
 /**
 *  \brief set data on port
 *  
 *  \param [in] port pointer on port
 *  \return status of port
 *  
 *  \details Details
 */tStatus setDataI2CSlave(const *tdata port);
 /**
 *  \brief renvoie la longueur de la donnée
 *  
 *  \param [in] port pointeur sur le port
 *  \return longueur des donnees
 *  
 *  \details Details
 */
 uint getDataLengthI2CSlave(const *tdata port);
 
 /**
 *  \brief renvoi le statu du port
 *  
 *  \param [in] port pointeur sur le port
 *  \return statu
 *  
 *  \details Details
 */
 tStatus getStatusI2CSlave();
 