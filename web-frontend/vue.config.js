module.exports = {
  "transpileDependencies": [
    "vuetify"
  ],
  chainWebpack: config => {
    if(config.plugins.has('extract-css')) {
      const extractCSSPlugin = config.plugin('extract-css')
      extractCSSPlugin && extractCSSPlugin.tap(() => [{
        filename: 'css/app.css',
        chunkFilename: 'css/chunk.css'
      }])
    }
  },
  configureWebpack: {
    output: {
      filename: 'js/app.js',
      chunkFilename: 'js/chunk.js'
    }
  },
  pluginOptions: {
    i18n: {
      locale: 'en',
      fallbackLocale: 'en',
      enableInSFC: true
    }
  }
}
