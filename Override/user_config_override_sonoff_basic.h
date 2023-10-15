/*
  user_config_override.h - user configuration overrides user_config.h for Sonoff-Tasmota

  Copyright (C) 2018  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
/////////////////////////////////////////////////////
/// Customized : Sonoff Basic R2/R3 for Retail
/////////////////////////////////////////////////////

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is inlcuded
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *         ie2 : enable in file platformio.ini "build_flags = -Wl,-Tesp8266.flash.1m0.ld -DUSE_CONFIG_OVERRIDE"
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*********************************************************************************************\
 * SECTION 1
 * - After initial load any change here only take effect if CFG_HOLDER is changed too
\*********************************************************************************************/

// -- Master parameter control --------------------
#undef CFG_HOLDER
#define CFG_HOLDER 4617 // [Reset 1] Change this value to load SECTION1 configuration parameters to flash   (default: 4617)

#undef SAVE_DATA
#define SAVE_DATA 1 // [SaveData] Save changed parameters to Flash (0 = disable, 1 - 3600 seconds)

#undef SAVE_STATE
#define SAVE_STATE 1 // [SetOption0] Save changed power state to Flash (0 = disable, 1 = enable)

// -- Project -------------------------------------
#undef PROJECT
#define PROJECT "RACKSYNC-BASIC" // PROJECT is used as the default topic delimiter

#undef FALLBACK_MODULE 
#define FALLBACK_MODULE SONOFF_BASIC

#undef MODULE
#define MODULE SONOFF_BASIC // [Module] Select default model from sonoff_template.h (Should not be changed)

// -- WIFI ---------------------------------------

//#undef STA_SSID1
//#define STA_SSID1 "WIFI" // [Ssid1] Wifi SSID

//#undef STA_PASS1
//#define STA_PASS1 "PASSWD" // [Password1] Wifi password

// #undef STA_SSID2
// #define STA_SSID2              ""                // [Ssid2] Optional alternate AP Wifi SSID

// #undef STA_PASS2
// #define STA_PASS2              ""                // [Password2] Optional alternate AP Wifi password

// -- mDNS ----------------------------------------
#undef MDNS_ENABLED
#define MDNS_ENABLED true // [SetOption55] Use mDNS (false = Disable, true = Enable)

#undef USE_DISCOVERY
#define USE_DISCOVERY // Enable mDNS for the following services (+8k code or +23.5k code with core 2_5_x, +0.3k mem)

#undef WEBSERVER_ADVERTISE
#define WEBSERVER_ADVERTISE // Provide access to webserver by name <Hostname>.local/

#undef MQTT_HOST_DISCOVERY
#define MQTT_HOST_DISCOVERY // Find MQTT host server (overrides MQTT_HOST if found)

// -- MQTT - Telemetry ----------------------------
#undef TELE_PERIOD
#define TELE_PERIOD 10 // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)

#undef MQTT_HOST
#define MQTT_HOST "homeassistant.local" // [MqttHost]

#undef MQTT_USER
#define MQTT_USER "mqtt" // [MqttUser] MQTT user

#undef MQTT_PASS
#define MQTT_PASS         "mqtt1234"



#undef MQTT_CLIENT_ID
#define MQTT_CLIENT_ID PROJECT "_%06X" // [MqttClient] Also fall back topic using Chip Id = last 6 characters of MAC address

// -- RETAIN STATUS
#undef MQTT_POWER_RETAIN
#define MQTT_POWER_RETAIN true // [PowerRetain] Power status message may send retain flag (false = off, true = on)

// -- MQTT --------------

#define MQTT_TOPIC PROJECT "_%06X"
#undef HOME_ASSISTANT_DISCOVERY_ENABLE
#define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

#undef USE_HOME_ASSISTANT
#define USE_HOME_ASSISTANT // Enable Home Assistant Discovery Support (+4.1k code, +6 bytes mem)

#undef HOME_ASSISTANT_DISCOVERY_PREFIX
#define HOME_ASSISTANT_DISCOVERY_PREFIX "homeassistant" // Home Assistant discovery prefix

#undef HASS_AS_LIGHT
#define HASS_AS_LIGHT false // [SetOption30] Enforce HAss autodiscovery as light

// -- Location ------------------------------------
#undef LATITUDE
#define LATITUDE 13.7563 // [Latitude] Your location to be used with sunrise and sunset
#undef LONGITUDE
#define LONGITUDE 100.5018 // [Longitude] Your location to be used with sunrise and sunset

// -- Application ---------------------------------
#undef APP_TIMEZONE
#define APP_TIMEZONE +7 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)

#undef APP_LEDSTATE
#define APP_LEDSTATE 8 // [LedState] Function of led \
                               //   (LED_OFF, LED_POWER, LED_MQTTSUB, LED_POWER_MQTTSUB, LED_MQTTPUB, LED_POWER_MQTTPUB, LED_MQTT, LED_POWER_MQTT)
#undef APP_DISABLE_POWERCYCLE
#define APP_DISABLE_POWERCYCLE true // [SetOption65] Disable fast power cycle detection for device reset

#undef APP_POWERON_STATE
#define APP_POWERON_STATE POWER_ALL_OFF // [PowerOnState] Power On Relay state \
                                        //   (POWER_ALL_OFF, POWER_ALL_ON, POWER_ALL_SAVED_TOGGLE, POWER_ALL_SAVED, POWER_ALL_ALWAYS_ON, POWER_ALL_OFF_PULSETIME_ON)

#undef KEY_ONLY_SINGLE_PRESS
#define KEY_ONLY_SINGLE_PRESS false // [SetOption13] Enable only single press to speed up button press recognition
// -- HTTP ----------------------------------------
#undef USE_WEBSERVER
#define USE_WEBSERVER // Enable web server and Wifi Manager (+66k code, +8k mem)
//#undef WEB_PORT
//#define WEB_PORT             80                // Web server Port for User and Admin mode

//#undef WEB_USERNAME
//#define WEB_USERNAME         "admin"           // Web server Admin mode user name

//#undef WEB_SERVER
//#define WEB_SERVER             2                 // [WebServer] Web server (0 = Off, 1 = Start as User, 2 = Start as Admin)

//#undef WEB_PASSWORD
//#define WEB_PASSWORD "racksync" // [WebPassword] Web server Admin mode Password for WEB_USERNAME (empty string = Disable)

#undef FRIENDLY_NAME
#define FRIENDLY_NAME PROJECT // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa


/*********************************************************************************************\
 *
 * UNDEFINE FUNCTION
 * 
\*********************************************************************************************/

#endif // _USER_CONFIG_OVERRIDE_H_
