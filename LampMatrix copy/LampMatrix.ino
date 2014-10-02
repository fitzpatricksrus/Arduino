// #include "FlexiTimer2.h"

// #include "MatrixColumnPattern.h"
#include "OutputPins.h"
#include "MatrixPins.h"
#include "ConcreteMatrixPattern.h"
#include <Arduino.h>
#include "Logging.h"

static const Time MS_PER_COLUMN = 8192;

// static int ROW_PIN_NUMBERS[] = { 3, 5, 6, 9, 10, 11 };
static int ROW_PIN_NUMBERS[] = { 3, 4 };
static OutputPins ROW_PINS(2, ROW_PIN_NUMBERS);
// static int COL_PIN_NUMBERS[] = { 2, 8, 4, 7, 12 };
static int COL_PIN_NUMBERS[] = { 5, 6  };
static OutputPins COL_PINS(2, COL_PIN_NUMBERS);
static MatrixPins LAMP_MATRIX(COL_PINS, ROW_PINS, MS_PER_COLUMN);

static ConcreteMatrixPattern<2,2>::ValueArray MATRIX_VALUES1 = {
		{ 51, 510 },
		{ 51, 510 },
};
static ConcreteMatrixPattern<2,2> PATTERN1(MATRIX_VALUES1);

static ConcreteMatrixPattern<2,2>::ValueArray MATRIX_VALUES2 = {
		{ 0, 0 },
		{ 0, 0 }
};
static ConcreteMatrixPattern<2,2> PATTERN2(MATRIX_VALUES2);


void setup() {
	Logging::DEFAULT_LOG.init(Logging::LOG_LEVEL_ERROR, 115200);
	LAMP_MATRIX.initialize();
	LAMP_MATRIX.setPattern(&PATTERN1);
}

void loop() {
	LAMP_MATRIX.refresh(millis());
/*	int stepCount = MS_PER_COLUMN;
	int step = MS_PER_COLUMN / stepCount;
	for (int i = 0; i < stepCount; i++) {
		int value = i * step;
		Serial.println(value);
		LAMP_MATRIX.refresh(value);
		delay(50);
	} */
}
