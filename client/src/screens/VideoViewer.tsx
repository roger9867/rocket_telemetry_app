import React, { useState, useRef } from 'react';
import { StyleSheet, View, TouchableOpacity, Text } from 'react-native';
import Video from 'react-native-video';

const VideoPlayer = () => {
  const [paused, setPaused] = useState(true);
  const videoRef = useRef<Video>(null);

  const togglePlayback = () => {
    setPaused((prev) => !prev);
  };

  return (
    <View>
      {/* VIDEO */}
      <View style={styles.container}>
        <Video
          ref={videoRef}
          source={{ uri: 'https://commondatastorage.googleapis.com/gtv-videos-bucket/sample/BigBuckBunny.mp4' }}
          style={{ width: '100%', height: 200 }}
          controls={false}
          paused={paused} // ✅ Dynamischer Zustand!
          resizeMode="contain"
        />
      </View>

      {/* STEUERUNG */}
      <View style={styles.controls}>
        <TouchableOpacity onPress={togglePlayback} style={styles.button}>
          <Text style={styles.buttonText}>{paused ? '▶️ Play' : '⏸️ Pause'}</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    width: '100%',
    height: 200,
    backgroundColor: 'black',
  },
  controls: {
    marginTop: 10,
    alignItems: 'center',
  },
  button: {
    backgroundColor: '#444',
    paddingVertical: 10,
    paddingHorizontal: 20,
    borderRadius: 6,
  },
  buttonText: {
    color: 'white',
    fontSize: 16,
  },
});

export default VideoPlayer;
