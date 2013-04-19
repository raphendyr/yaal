#ifndef __YAAL_INTERFACES__COMMUNICATION__
#define __YAAL_INTERFACES__COMMUNICATION__ 1
#include "../requirements.hh"
#ifdef __YAAL__

/*! Syncronous point-to-point communication interface
 *
 * All this kind of communication connections should implement
 * this interface.
 *
 * User of this kind of class can presume that at least
 * required methods are implemented
 *
 * FIXME: implement a way to know that is implemented.
 */
class SyncronousPointToPointCommunicationInterface {


    /* REQUIRED methods */

    /*! Setup connection
     */
    // NOTE: if constructors do start working, this will change to that and may be ommitted (in caller side)
    void setup();

    /*! Read data
     * This funktion reads sizeof(T) bytes from connection
     * and returns that.
     *
     * \return \a read returns sizeof(T) bytes of data from connection
     */
    template<typename T>
    T read();

    /*! Write data
     * This funktion writes sizeof(T) bytes of data from \a data
     * into connection.
     *
     * \param data bytes to be writtend.
     */
    template<typename T>
    void write(const T data);



    /** Optional methods **/

    template<typename T>
    T read(uint8_t amount_of_bits);

    template<typename T>
    void write(const T data_to_be_written, uint8_t amount_of_bits);



    /** Protocol specific **/

    template<typename T>
    T transfer(const T data_to_be_written);

    template<typename T>
    T transfer(const T data_to_be_written, uint8_t amount_of_bits);

    template<typename T>
    void exchange(T& data)

    template<typename T
    void exchange(T& data, uint8_t amount_of_bits);

};

#endif
#endif
