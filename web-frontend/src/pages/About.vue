<template>
	<v-container>
		<v-row class="text-center">
			<v-col cols="12">
				<v-img
					:src="require('../assets/logo.svg')"
					class="my-3"
					contain
					height="200"
				/>
			</v-col>

			<v-col class="mb-4">
				<h1 class="display-1 font-weight-bold mb-3">
					{{ $t('about.title') }}
				</h1>

				<p class="subheading font-weight-regular">
					{{ $t('about.text') }}
				</p>
			</v-col>
		</v-row>
	</v-container>
</template>