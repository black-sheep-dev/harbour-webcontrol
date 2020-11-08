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

## Planned Features

- Provide whole functionality of the Sailfish MDM Framework over the web interface
- User management and authentication (mandatory for controlling anything)
- JWT authentication for RESTful API (mandatory for controlling anything)
- More Sailfish OS look & feel for the web interface
- Feature requests

## Translations
- English
- German

## RESTful API
### Available endpoints
- /api (GET)
- /api/batteryinfo (GET)
- /api/deviceinfo (GET)
- /api/siminfo (GET)

## Donations

If you like my work, you can buy me a beer! [Buy](https://www.paypal.com/paypalme/nubecula/1)