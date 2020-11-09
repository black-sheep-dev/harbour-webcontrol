<template>
	<div>
		<v-icon>{{ icon }}</v-icon>
		<span>{{ devicestatus.battery.charge_percentage }}%</span>
	</div>
</template>

<script>
	import { mapState } from 'vuex';

	export default {
		name: 'battery-indicator',
		data: function () {
			return {
				icon: 'mdi-battery'
			}
		},
		beforeMount () {
			this.updateIcon();
		},
		methods: {
			updateIcon() {
				if (this.devicestatus.battery.charger_status === 1) {
					this.icon = 'mdi-battery-charging';
				} else {
					var count = Math.round(this.devicestatus.battery.charge_percentage / 10 - 0.5) * 10;

					if (count < 100) {
						this.icon = 'mdi-battery-' + count;
					} else {
						this.icon = 'mdi-battery';
					}
					
				}
			}
		},
		watch: {
			devicestatus: function () {
				this.updateIcon();
			}
		},
		computed: mapState([
			'devicestatus'
		])
	}
</script>