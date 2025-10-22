import React from 'react';
import { WebView } from 'react-native-webview';
import { StyleSheet, View } from 'react-native';

const ModelViewer = () => {
  const html = `
    <!DOCTYPE html>
    <html>
      <head>
        <script src="https://unpkg.com/@google/model-viewer/dist/model-viewer.min.js"></script>
        <style>
          body {
            margin: 0;
            background-color: #212121;
            height: 100vh;
            overflow: hidden;
          }
          model-viewer {
            width: 100%;
            height: 100vh;
          }
        </style>
      </head>
      <body>
        <model-viewer 
          src="file:///android_asset/rocket_mobile_emb.glb"
          alt="3D Modell"
          auto-rotate
          camera-controls
          background-color="#212121">
        </model-viewer>
      </body>
    </html>
  `;

  return (
    <View style={styles.container}>
      <WebView
        originWhitelist={['*']}
        javaScriptEnabled={true}
        domStorageEnabled={true}
        allowFileAccess={true}                // WICHTIG für lokalen Zugriff
        allowingReadAccessToURL={'file://'}  // ebenfalls wichtig
        source={{ html }}
        style={styles.webview}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    width: '100%',
    height: 300,
    backgroundColor: '#212121',
  },
  webview: {
    flex: 1,
  },
});

export default ModelViewer;
