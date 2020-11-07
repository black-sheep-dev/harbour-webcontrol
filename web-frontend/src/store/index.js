import Vue from 'vue'
import Vuex from 'vuex'


Vue.use(Vuex)

export default new Vuex.Store({
	state: {
		batteryinfo: {},
		deviceinfo: {},
		siminfo: {},
	},
	mutations: {
		SET_BATTERYINFO (state, info) {
			state.batteryinfo = info;
		},
		SET_DEVICEINFO (state, info) {
			state.deviceinfo = info;
		},
		SET_SIMINFO (state, info) {
			state.siminfo = info;
		}
	},
	actions: {
		loadBatteryInfo ({commit}) {
			Vue.axios.get('/api/batteryinfo')
				.then(r => r.data)
				.then(info => {
					commit('SET_BATTERYINFO', info);
				}).catch(err => {
					console.log(err);
				})
		},
		loadDeviceInfo ({commit}) {
			Vue.axios.get('/api/deviceinfo')
				.then(r => r.data)
				.then(info => {
					commit('SET_DEVICEINFO', info);
				}).catch(err => {
					console.log(err);
				})
		},
		loadSimInfo ({commit}) {
			Vue.axios.get('/api/siminfo')
				.then(r => r.data)
				.then(info => {
					commit('SET_SIMINFO', info);
				}).catch(err => {
					console.log(err);
				})
		}
	},
	modules: {

	}
})
