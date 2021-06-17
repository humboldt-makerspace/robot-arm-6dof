#include "system/Setup.hpp"
#include "system/Interface.hpp"

void initBT (void)
{
	BTSerial::bt.begin(BT_ID);
	Serial.println("Bluetooth initialized");
}

void initButton (void)
{
	pinMode(RED_BUTTON_PIN, INPUT_PULLUP);
	Interface::btnPressed = false;
}

void initWifi (void)
{
	Serial.print("MAC: ");
	Serial.println(WiFi.macAddress());

	WiFi.mode(WIFI_STA);
	WiFi.begin(SSID_CUSTOM, PW_CUSTOM);
	Serial.println();
	Serial.print("Wait for WiFi... ");

	while (WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(500);
	}
	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
	UDPManager::UDPServer.begin(UDP_PORT);

	configTime(TIME_ZONE * 3600, DST * 0, NTP_SERVER);
  	Serial.println("\nWaiting for time");
  	while (!time(nullptr)) {
    	Serial.print(".");
    	delay(1000);
  	}
  	Serial.println("");
	time_t now = time(nullptr);
  	Serial.println(ctime(&now));
}

void Setup::init (void)
{
	Serial.begin(BAUD_RATE);
	//initWifi();
	initButton();
	initBT();
	PWMDriver::init();
	Serial.println(WiFi.macAddress());
}
