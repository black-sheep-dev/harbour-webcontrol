<template>
	<v-card
		class="mx-auto"
		max-width="400"
		>
		<v-card-title>
			<v-icon
			large
			left
			>
				mdi-sim
			</v-icon>
			<span class="title">{{ $t('sim.title') + ' ' + id }}</span>
		</v-card-title>

		<v-list-item>
			<v-list-item-title>{{ $t('sim.enabled') }}</v-list-item-title>
			<v-list-item-subtitle>
				<div v-if="sim.enabled">
					{{ $t("true") }}
				</div>
				<div v-else>
					{{ $t("false") }}
				</div> 
			</v-list-item-subtitle>
		</v-list-item>
		<v-list-item>
			<v-list-item-title>{{ $t('sim.present') }}</v-list-item-title>
			<v-list-item-subtitle>
				<div v-if="sim.present">
					{{ $t("true") }}
				</div>
				<div v-else>
					{{ $t("false") }}
				</div> 
			</v-list-item-subtitle>
		</v-list-item>
		<v-list-item>
			<v-list-item-title>{{ $t('sim.identifier') }}</v-list-item-title>
			<v-list-item-subtitle>{{ sim.card_identifier }}</v-list-item-subtitle>
		</v-list-item>
		<v-list-item>
			<v-list-item-title>{{ $t('sim.imei') }}</v-list-item-title>
			<v-list-item-subtitle>{{ sim.imei }}</v-list-item-subtitle>
		</v-list-item>
		<v-list-item>
			<v-list-item-title>{{ $t('sim.imsi') }}</v-list-item-title>
			<v-list-item-subtitle>{{ sim.imsi }}</v-list-item-subtitle>
		</v-list-item>
		<v-list-item>
			<v-list-item-title>{{ $t('sim.voice') }}</v-list-item-title>
			<v-list-item-subtitle>
				<div v-if="sim.voice_sim">
					{{ $t("true") }}
				</div>
				<div v-else>
					{{ $t("false") }}
				</div> 
			</v-list-item-subtitle>
		</v-list-item>
		<v-list-item>
			<v-list-item-title>{{ $t('sim.data') }}</v-list-item-title>
			<v-list-item-subtitle>
				<div v-if="sim.data_sim">
					{{ $t("true") }}
				</div>
				<div v-else>
					{{ $t("false") }}
				</div> 
			</v-list-item-subtitle>
		</v-list-item>
		<v-list-item>
			<v-list-item-title>{{ $t('sim.modem-path') }}</v-list-item-title>
			<v-list-item-subtitle>{{ sim.modem_path }}</v-list-item-subtitle>
		</v-list-item>
	</v-card>
</template>

<script>
	export default {
		name: 'sim-info-card',
		props: [
			'id',
			'sim'
		],
		data: () => ({
			//
		}),
	}
</script>