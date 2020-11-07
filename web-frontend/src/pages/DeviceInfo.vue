<template>
	<v-container>
		<v-row>
			<v-col class="mb-4">
				<v-card
					class="mx-auto"
					max-width="400"
					>
					<v-img
						:aspect-ratio="16/9"
						class="white--text align-end"
						height="100px"
						src="https://jolla.com/content/uploads/2017/02/newsarticleupdate.jpg"
						>
						<v-card-title>{{ deviceinfo.product_name }}</v-card-title>
					</v-img>

					<v-list-item>
						<v-list-item-title>{{ $t('device.manufacturer') }}</v-list-item-title>
						<v-list-item-subtitle>{{ deviceinfo.manufacturer }}</v-list-item-subtitle>
					</v-list-item>
					<v-list-item>
						<v-list-item-title>{{ $t('device.product-name') }}</v-list-item-title>
						<v-list-item-subtitle>{{ deviceinfo.product_name }}</v-list-item-subtitle>
					</v-list-item>
					<v-list-item>
						<v-list-item-title>{{ $t('device.model') }}</v-list-item-title>
						<v-list-item-subtitle>{{ deviceinfo.device_model }}</v-list-item-subtitle>
					</v-list-item>
					<v-list-item>
						<v-list-item-title>{{ $t('device.software-version') }}</v-list-item-title>
						<v-list-item-subtitle>{{ deviceinfo.software_version }}</v-list-item-subtitle>
					</v-list-item>

					<v-list-item>
						<v-list-item-title>{{ $t('device.bluetooth-mac') }}</v-list-item-title>
						<v-list-item-subtitle>{{ deviceinfo.bluetooth_mac }}</v-list-item-subtitle>
					</v-list-item>
					<v-list-item>
						<v-list-item-title>{{ $t('device.wlan-mac') }}</v-list-item-title>
						<v-list-item-subtitle>{{ deviceinfo.wlan_mac }}</v-list-item-subtitle>
					</v-list-item>
				</v-card>
			</v-col>
		</v-row>
	</v-container>
</template>

<script>
	import { mapState } from 'vuex';

	export default {
		name: 'deviceinfo',
		beforeMount () {
			this.refresh();
		},
		methods: {
			refresh: function () {
				this.$store.dispatch('loadDeviceInfo')
			}
		},
		computed: mapState([
			'deviceinfo'
		])
	}
</script>