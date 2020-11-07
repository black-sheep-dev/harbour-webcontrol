<template>
	<v-container>
		<v-row>
			<v-col 
				v-for="(sim, index) in siminfo.sim_cards"
				:key="sim.card_identifier"
				class="mb-4"
				>
				<sim-info-card :sim="sim" :id="index + 1" />
			</v-col>
		</v-row>
	</v-container>
</template>

<script>
	import { mapState } from 'vuex';

	import SimInfoCard from '@/components/SimInfoCard'

	export default {
		name: 'deviceinfo',
		components: {
			SimInfoCard
		},
		beforeMount () {
			this.refresh();
		},
		methods: {
			refresh: function () {
				this.$store.dispatch('loadSimInfo')
			}
		},
		computed: mapState([
			'siminfo'
		])
	}
</script>