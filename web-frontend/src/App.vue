<template>
  <component :is="layout">
    <router-view />
  </component>
</template>

<script>
  const default_layout = "default";
  
  export default {
    props: {
      source: String,
    },
    computed: {
      layout() {
        return (this.$route.meta.layout || default_layout) + '-layout';
      }
    }
  };
</script>