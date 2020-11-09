<template>
	<v-container>
		<v-row>
			<v-col class="mb-6">
				<v-card
					class="mx-auto"
					max-width="400"
					>
					<v-list two-line>
						<template v-for="(app, index) in apps">
							<v-list-item :key="index">
								<v-list-item-avatar tile>
									<v-img :src="'data:image/png;base64,' + app.icon"></v-img>
								</v-list-item-avatar>
								<v-list-item-content>
									<v-list-item-title v-html="app.name"></v-list-item-title>
									<v-list-item-subtitle v-html="app.package"></v-list-item-subtitle>
								</v-list-item-content>

								<v-list-item-action>
									<v-btn icon>
										<v-icon color="grey lighten-1">mdi-delete</v-icon>
									</v-btn>
								</v-list-item-action>
							</v-list-item>
						</template>
					</v-list>
				</v-card>
			</v-col>
		</v-row>
	</v-container>
</template>

<script>
	import { mapState } from 'vuex';

	export default {
		name: 'app-list',
		beforeMount () {
			this.refresh();
		},
		methods: {
			refresh: function () {
				this.$store.dispatch('loadApps')
			}
		},
		computed: mapState([
			'apps'
		])
	}
</script>