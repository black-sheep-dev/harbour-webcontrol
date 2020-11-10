<template>
	<div>
		<v-navigation-drawer
			absolute
			
			>
			<v-list-item-group
				v-model="selectedContact"
				color="primary"
				>
				<v-list>
					<template v-for="(contact, index) in contacts">
						<v-list-item :key="index">
							<v-list-item-avatar v-if="contact.avatar.image.length > 0">
								<v-img :src="getUrl(contact.avatar.image)"></v-img>
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
		</v-navigation-drawer>
		<v-main>
			<v-container flex>
				<v-row>
					<v-col>
						<v-card
							class="mx-auto"
							
							>
							<v-list-item>
								<v-list-item-avatar size="96" v-if="contact.avatar.image.length > 0">
									<v-img :src="getUrl(contact.avatar.image)"></v-img>
								</v-list-item-avatar>
								<v-list-item-avatar size="96" v-else color="grey">
									<v-icon size="86" dark>mdi-account</v-icon>
								</v-list-item-avatar>
								<v-list-item-content>
									<v-list-item-title v-html="contact.name.first + ' ' + contact.name.last"></v-list-item-title>
								</v-list-item-content>
							</v-list-item>
						</v-card>
					</v-col>
				</v-row>
			</v-container>
		</v-main>
	</div>
</template>

<script>
	import { mapState } from 'vuex';

	export default {
		name: 'contact-list',
		data: function () {
			return {
				contact: null,
				selectedContact: 0
			}
		},
		beforeMount () {
			this.refresh();
			this.contact = this.contacts[this.selectedContact];
		},
		methods: {
			getUrl: function (url) {
				return this.$baseUrl + url;
			},
			getScreenHeight: function () {
				return window.innerHeight * 0.8;
			},
			refresh: function () {
				this.$store.dispatch('loadContacts');
			}
		},
		watch: {
			contacts: function () {
				this.contact = this.contacts[0];
			},
			selectedContact: function () {
				this.contact = this.contacts[this.selectedContact];
				console.log(this.contact.avatar.image);
			}
		},
		computed: mapState([
			'contacts'
		])
	}
</script>