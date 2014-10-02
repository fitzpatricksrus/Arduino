/*
 * OutputPins.h
 *
 *  Created on: Sep 24, 2014
 *      Author: Dad
 */

#ifndef OUTPUTPINS_H_
#define OUTPUTPINS_H_

class OutputPins {
public:
    OutputPins(int pinCount, int pins[]);
    OutputPins(const OutputPins& source);
	~OutputPins();
	OutputPins& operator=(const OutputPins& other);
    void initializePins(int value);
    void initializeDigitalPins(int value);
    int getPin(int pinNdx) const;
    int operator[](int pinNdx) const;
    void setAnalogPin(int pinNdx, int value);
    void setDigitalPin(int pinNdx, int value);
    void setAnalog(int value);
    void setDigital(int value);
    int getPinCount() const;
private:
    int* pinNumber;
    int* pinValue;
    int pinCount;
};
#endif /* OUTPUTPINS_H_ */
