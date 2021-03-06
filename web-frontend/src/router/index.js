import Vue from 'vue'
import VueRouter from 'vue-router'

import About from  '@/pages/About.vue'
import AppList from '@/pages/AppList.vue'
import ContactList from '@/pages/ContactList.vue'
import DeviceInfo from '@/pages/DeviceInfo.vue'
import Overview from '@/pages/Overview.vue'
import SimInfo from '@/pages/SimInfo.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Home',
    meta: { 
      layout: "dashboard",
    },
    component: Overview
  },
  {
    path: '/contacts',
    name: 'Contacts',
    meta: { 
      layout: "dashboard",
    },
    component: ContactList
  },
  {
    path: '/apps',
    name: 'Apps',
    meta: { 
      layout: "dashboard",
    },
    component: AppList
  },
  {
    path: '/deviceinfo',
    name: 'Device Info',
    meta: { 
      layout: "dashboard",
    },
    component: DeviceInfo
  },
  {
    path: '/siminfo',
    name: 'Sim Info',
    meta: { 
      layout: "dashboard",
    },
    component: SimInfo
  },
  {
    path: '/about',
    name: 'About',
    meta: { 
      layout: "dashboard",
    },
    component: About
  }
]

const router = new VueRouter({
  routes
})

export default router
