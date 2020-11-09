// plugins/i18n.js
import Vue from 'vue';
import VueI18n from 'vue-i18n';

Vue.use(VueI18n);

export const i18n = new VueI18n({
	locale: 'en',
	fallbackLocale: 'en',
	messages: {
		en: {
			'about': {
				'text': 'Sailfish OS Web Control let you control your Sailfish OS device within a browser.',
				'title': 'Sailfish OS Web Control',
			},
			'device': {
				'bluetooth-mac': 'Bluetooth MAC',
				'manufacturer': 'Manufacturer',
				'model': 'Model',
				'product-name': 'Product Name',
				'software-version': 'Software Version',
				'uid': 'Device UID',
				'wlan-mac': 'WLAN MAC',
			},
			'false': 'false',
			'menu': {
				'about': 'About',
				'apps': 'Applications',
				'contacts': 'Contacts',
				'deviceinfo': 'Device Info',
				'overview': 'Overview',
				'siminfo': 'Sim Info',
			},
			'overview': {
				'title': 'Welcome to Sailfish OS Web Control',
			},
			'sim': {
				'data': 'Data SIM',
				'enabled': 'Enabled',
				'identifier': 'Identifier',
				'imei': 'IMEI',
				'imsi': 'IMSI',
				'modem-path': 'Modem Path',
				'present': 'Present',
				'title': 'SIM',
				'voice': 'Voice SIM',
			},
			'true': 'true',
		},
		de: {
			'about': {
				'text': 'Mit Sailfish OS Web Control kannst du dein Sailfish OS Gerät vom Browser aus steuern.',
				'title': 'Sailfish OS Web Control',
			},
			'device': {
				'bluetooth-mac': 'Bluetooth MAC',
				'manufacturer': 'Hersteller',
				'model': 'Modell',
				'product-name': 'Produkt Name',
				'software-version': 'Software Version',
				'uid': 'Geräte UID',
				'wlan-mac': 'WLAN MAC',
			},
			'menu': {
				'about': 'Über',
				'apps': 'Anwendungen',
				'contacts': 'Kontakte',
				'deviceinfo': "Geräte Info",
				'overview': 'Übersicht',
				'siminfo': 'Sim Info',
			},
			'overview': {
				'title': 'Willkommen zu Sailfish OS Web Control',
			},
			'sim': {
				'data': 'Data SIM',
				'enabled': 'Aktiviert',
				'identifier': 'Identifier',
				'imei': 'IMEI',
				'imsi': 'IMSI',
				'modem-path': 'Modem Pfad',
				'present': 'Verfügbar',
				'title': 'SIM',
				'voice': 'Voice SIM',
			},
		},
	}
});