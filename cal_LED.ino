int sensorPin = A0;
int duration = 1000;

int calibrationZero;
int calibrationOne;

void setup () {
	Serial.begin(9600);
	pinMode(sensorPin, INPUT);	

	// Far
	Serial.print("Far calibration...");
	delay(duration);

	int sensorCumulativeValue = 0;
	int reads = 0;
	unsigned long timeStart = millis();
	do {
		delay(20);
		sensorCumulativeValue += analogRead(sensorPin);
		reads ++;
	} while (millis() <= timeStart + duration);
	calibrationZero = sensorCumulativeValue / reads;

	Serial.print(calibrationZero);
	Serial.println();

	// Close
	Serial.print("Close calibration...");
	delay(duration);

	sensorCumulativeValue = 0;
	reads = 0;
	timeStart = millis();
	do {
		delay(20);
		sensorCumulativeValue += analogRead(sensorPin);
		reads ++;
	} while (millis() <= timeStart + duration);
	calibrationOne = sensorCumulativeValue / reads;

	Serial.print(calibrationOne);
	Serial.println();
}

int getDistanceReading (int readings = 5) {
	int sensorCumulativeValue = 0;
	for (int i = 0; i < readings; i ++) {
		delay(20);
		sensorCumulativeValue += analogRead(sensorPin);
	}

	int distance = map
		(
		 sensorCumulativeValue / readings,
		 sensorCalibrationZero, sensorCalibrationOne,
		 0, 255
		);
	return constrain(distance, 0, 255);
}


void loop () {

int distance = getDistanceReading ();
	Serial.println(distance);
}

