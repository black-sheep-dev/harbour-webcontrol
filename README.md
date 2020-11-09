# Sailfish OS Web Control
Web Control is a Sailfish OS app to manage the device over a web interface in your browser.

>![](app/icons/128x128/harbour-webcontrol.png)

## Current state of development

This app is a Proof of Concept for a web interface for Sailfish OS devices.
At the moment there is no real functionality, only showing some device informations in the web interface.

Do we need such an app at all?  
What should be implemented?

Your are welcome to make some suggestions.

## Implemented Features
- Web Server using awesome [QtWebApp library](https://github.com/StefanFrings/QtWebApp) from Stefan Frings 
- RESTful API
- Web interface using [Vue.js](https://vuejs.org/) with [Vuetify Framework](https://vuetifyjs.com) (not so fancy at the moment)

#### Web Interface Features
- Show SIM card(s) info
- Show device info
- Battery indicator
- Device lock indicator
- Show installed apps
- Show phone contacts

## Planned / Requested Features

- Provide whole functionality of the Sailfish MDM Framework over the web interface
- User management and authentication (mandatory for controlling anything)
- JWT authentication for RESTful API (mandatory for controlling anything)
- More Sailfish OS look & feel for the web interface
- File browser
- Media viewer
- Notifications
- SMS
- Feature requests

## Translations
- Chinese (thanks to dashinfrantry)
- English
- German

## RESTful API
### Available endpoints
- /api (GET)
- /api/apps (GET)
- /api/batteryinfo (GET)
- /api/device/info (GET)
- /api/device/status (GET)
- /api/siminfo (GET)
- /api/update (GET)

## Donations

If you like my work, you can buy me a beer! [Buy](https://www.paypal.com/paypalme/nubecula/1)