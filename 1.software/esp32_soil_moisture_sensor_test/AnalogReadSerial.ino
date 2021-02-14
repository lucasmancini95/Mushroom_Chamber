//https://maker.pro/arduino/projects/arduino-soil-moisture-sensor#:~:text=When%20taking%20the%20analog%20output,them%20on%20the%20serial%20monitor.

#define ADC_SENSOR_PIN 34
#define SENSOR_VALUE_RAW_DRY_SOIL 4096
#define SENSOR_VALUE_RAW_WET_SOIL 10


int board_soil_moisture_get_value(int pin);

static int sensor_value = 0;
void setup() {

  Serial.begin(115200);
  Serial.println("Moisture Sensor Test:");
  delay(2000);
}

void loop() {

	Serial.print("Mositure : ");
	Serial.print(board_soil_moisture_get_value(ADC_SENSOR_PIN));
	Serial.println("%");
	delay(1000);

}


int board_soil_moisture_get_value(int pin){

	int aux_sensor_value=0;

	aux_sensor_value = analogRead(pin);

	aux_sensor_value = map(aux_sensor_value,
						SENSOR_VALUE_RAW_DRY_SOIL,SENSOR_VALUE_RAW_WET_SOIL,
						0,100); //to get the RH in "%"

	return aux_sensor_value;

}
