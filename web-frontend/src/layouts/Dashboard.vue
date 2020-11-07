<template>
  <v-app>
    <v-navigation-drawer
      v-model="drawer"
      app
    >
      <v-list dense>
			<v-list-item link to="/">
				<v-list-item-action>
					<v-icon>mdi-home</v-icon>
				</v-list-item-action>
				<v-list-item-content>
					<v-list-item-title>{{ $t('menu.overview') }}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>
			<v-list-item link to="/deviceinfo">
				<v-list-item-action>
					<v-icon>mdi-cellphone</v-icon>
				</v-list-item-action>
				<v-list-item-content>
					<v-list-item-title>{{ $t('menu.deviceinfo') }}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>
			<v-list-item link to="/siminfo">
				<v-list-item-action>
					<v-icon>mdi-sim</v-icon>
				</v-list-item-action>
				<v-list-item-content>
					<v-list-item-title>{{ $t('menu.siminfo') }}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>
			<v-list-item link to="/about">
				<v-list-item-action>
					<v-icon>mdi-information</v-icon>
				</v-list-item-action>
				<v-list-item-content>
					<v-list-item-title>{{ $t('menu.about') }}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>
		</v-list>
    </v-navigation-drawer>

    <v-app-bar app dark>
      <v-app-bar-nav-icon @click="drawer = !drawer"></v-app-bar-nav-icon>

      <div class="d-flex align-center">
        <v-img
          alt="Web Control Logo"
          class="shrink mr-2"
          contain
          :src="require('@/assets/logo.svg')"
          transition="scale-transition"
          width="40"
        />
      </div>

      <v-toolbar-title>Sailfish OS Web Control</v-toolbar-title>
      <v-spacer></v-spacer>
      <battery-indicator />
    </v-app-bar>
    <v-main>
      <v-container fluid>
				<transition 
					name="fade"
					mode="out-in">
					<slot />
				</transition>
			</v-container>
    </v-main>
    <v-footer app :absolute="false">
		<span>&copy; {{ year() }}, Black Sheep</span>
	</v-footer>
  </v-app>
</template>

<script>
	import BatteryIndicator from '@/components/BatteryIndicator'

	export default {
		data: () => ({ drawer: null }),
		components: {
			BatteryIndicator
		},
		methods: {
			year: function() {
				return new Date().getFullYear();
			}
		}
	}
</script>

<style>
	.fade-enter-active, .fade-leave-active {
		//position: fixed;
		//width: inherit;

		transition: opacity .5s;
	}

	.fade-enter, .fade-leave-to {
		opacity: 0;
	}
</style>
