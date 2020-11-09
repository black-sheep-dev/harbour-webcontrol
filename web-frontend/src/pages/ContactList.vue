<template>
	<div>
		<v-list-item-group
			v-model="selectedContact"
			color="primary"
			>
			<v-list max-width="300" :max-height="getScreenHeight()" class="overflow-y-auto">
				<template v-for="(contact, index) in contacts">
					<v-list-item :key="index">
						<v-list-item-avatar v-if="contact.avatar.image.length > 0">
							<v-img :src="'data:image/jpg;base64,' + contact.avatar.image"></v-img>
						</v-list-item-avatar>
						<v-list-item-avatar v-else color="grey">
							<v-icon dark>mdi-account</v-icon>
						</v-list-item-avatar>
						<v-list-item-content>
							<v-list-item-title v-html="contact.name.first + ' ' + contact.name.last"></v-list-item-title>
						</v-list-item-content>
					</v-list-item>
				</template>
			</v-list>
		</v-list-item-group>	
		<v-row>
			<v-col>
				<v-card
					class="mx-auto"
					max-width="600"
					>
					
				</v-card>
			</v-col>
		</v-row>
	</div>
</template>

<script>
	import { mapState } from 'vuex';

	export default {
		name: 'contact-list',
		data: function () {
			return {
				selectedContact: 1
			}
		},
		beforeMount () {
			this.refresh();
		},
		methods: {
			getScreenHeight: function () {
				return window.innerHeight * 0.8;
			},
			refresh: function () {
				this.$store.dispatch('loadContacts')
			}
		},
		computed: mapState([
			'contacts'
		])
	}
</script>