<template>
	<div>
		<v-icon>{{ icon }}</v-icon>
		<span>{{ batteryinfo.charge_percentage }}%</span>
	</div>
</template>

<script>
	import { mapState } from 'vuex';

	export default {
		name: 'battery-indicator',
		data: function () {
			return {
				icon: 'mdi-battery',
				interval: '',
			}
		},
		beforeMount () {
			this.refresh();
			this.interval = setInterval(() => {
				this.refresh();
			}, 5000);
		},
		methods: {
			refresh: function () {
				this.$store.dispatch('loadBatteryInfo')
					// eslint-disable-next-line
					.then(response => {
						this.updateIcon();
					})
			},
			updateIcon() {
				if (this.batteryinfo.charger_status === 1) {
					this.icon = 'mdi-battery-charging';
				} else {
					var count = Math.round(this.batteryinfo.charge_percentage / 10 - 0.5) * 10;
					console.log(count);

					if (count < 100) {
						this.icon = 'mdi-battery-' + count;
					} else {
						this.icon = 'mdi-battery';
					}
					
				}
			}
		},
		computed: mapState([
			'batteryinfo'
		])
	}
</script>