import Vue from 'vue'
import './plugins/axios'
import App from './App.vue'
import vuetify from './plugins/vuetify';

Vue.config.productionTip = false

// base url
let BASE_URL;

if (process.env.NODE_ENV === 'development') 
	BASE_URL = process.env.VUE_APP_ROOT_API;
else
	BASE_URL = window.location.protocol + '//' + window.location.hostname;

Vue.prototype.$baseUrl = BASE_URL


// i18n
import { i18n } from '@/plugins/i18n.js';

// router
import router from './router'

// layouts
import DashboardLayout from '@/layouts/Dashboard';

import store from './store'
Vue.component('dashboard-layout', DashboardLayout);

new Vue({
	vuetify,
	i18n,
	router,
	render: h => h(App),
	store,
	data () {
		return {
			statusRefreshInterval: null,
		}
	},
	methods: {
		refreshDeviceStatus () {
			store.dispatch('loadDeviceStatus');
		},
	},
	beforeMount() {
		if (navigator.languages != undefined) {
			this.$i18n.locale = navigator.languages[0].substr(0, 2);
			this.$vuetify.lang.current = navigator.languages[0].substr(0, 2);
		} else {
			this.$i18n.locale = navigator.language.substr(0, 2);
			this.$vuetify.lang.current = navigator.language.substr(0, 2);
		}

		this.refreshDeviceStatus();
		/*
		this.statusRefreshInterval = setInterval(() => {
			this.refreshDeviceStatus();
		}, 5000);
		*/
	},
}).$mount('#app')
