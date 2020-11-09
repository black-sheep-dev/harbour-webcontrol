import Vue from 'vue'
import Vuex from 'vuex'


Vue.use(Vuex)

export default new Vuex.Store({
	state: {
		apps: [],
		batteryinfo: {},
		contacts: [],
		deviceinfo: {},
		devicestatus: {
			battery: {
				charge_percentage: 0,
				charger_status: 0,
			},
		},
		siminfo: {},
	},
	mutations: {
		SET_APPS(state, apps) {
			state.apps = apps;
		},
		SET_BATTERY_INFO (state, info) {
			state.batteryinfo = info;
		},
		SET_CONTACTS (state, contacts) {
			state.contacts = contacts
		},
		SET_DEVICE_INFO (state, info) {
			state.deviceinfo = info;
		},
		SET_DEVICE_STATUS (state, devicestatus) {
			state.devicestatus = devicestatus
		},
		SET_SIM_INFO (state, info) {
			state.siminfo = info;
		}
	},
	actions: {
		loadApps ({commit}) {
			Vue.axios.get('/api/apps')
				.then(r => r.data)
				.then(apps => {
					commit('SET_APPS', apps);
				}).catch(err => {
					console.log(err);
				})
		},
		loadBatteryInfo ({commit}) {
			Vue.axios.get('/api/batteryinfo')
				.then(r => r.data)
				.then(info => {
					commit('SET_BATTERY_INFO', info);
				}).catch(err => {
					console.log(err);
				})
		},
		loadContacts ({commit}) {
			Vue.axios.get('/api/contacts')
				.then(r => r.data)
				.then(contacts => {
					commit('SET_CONTACTS', contacts);
				}).catch(err => {
					console.log(err);
				})
		},
		loadDeviceInfo ({commit}) {
			Vue.axios.get('/api/device/info')
				.then(r => r.data)
				.then(info => {
					commit('SET_DEVICE_INFO', info);
				}).catch(err => {
					console.log(err);
				})
		},
		loadDeviceStatus ({commit}) {
			Vue.axios.get('/api/device/status')
				.then(r => r.data)
				.then(devicestatus => {
					commit('SET_DEVICE_STATUS', devicestatus);
				}).catch(err => {
					console.log(err);
				})
		},
		loadSimInfo ({commit}) {
			Vue.axios.get('/api/siminfo')
				.then(r => r.data)
				.then(info => {
					commit('SET_SIM_INFO', info);
				}).catch(err => {
					console.log(err);
				})
		}
	},
	modules: {

	}
})
