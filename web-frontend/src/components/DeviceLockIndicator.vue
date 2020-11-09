<template>
	<div>
		<v-icon v-if="devicestatus.device_lock.state == 0">mdi-cellphone</v-icon>
		<v-icon v-else>mdi-cellphone-lock</v-icon>
	</div>
</template>

<script>
	import { mapState } from 'vuex';

	export default {
		name: 'device-lock-indicator',
		computed: mapState([
			'devicestatus'
		])
	}
</script>