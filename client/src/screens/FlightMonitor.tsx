import React from 'react';
import { View, Text, StyleSheet, FlatList, ScrollView } from 'react-native';
import { RouteProp, useRoute } from '@react-navigation/native';
import { RootStackParamList } from '../navigation/types';
import Video from 'react-native-video';
import ModelViewer from '../components/ModelViewer'; // Passe ggf. den Pfad an


type FlightMonitorRouteProp = RouteProp<RootStackParamList, 'FlightMonitor'>;

const FlightMonitor: React.FC = () => {
  const route = useRoute<FlightMonitorRouteProp>();
  const { flight } = route.params;

  return (
    <ScrollView contentContainerStyle={styles.container}>
      <Text style={styles.title}>Flight Monitor</Text>

      {/* Video Box */}
      <View style={styles.videoBox}>
        <Video
    source={{ uri: 'https://www.w3schools.com/html/mov_bbb.mp4' }} // Beispiel-Video
    style={styles.video}
    controls={true}
    resizeMode="contain"
  />
      </View>

      {/* 3D Viewer + Liste nebeneinander */}
      <View style={styles.row}>
        <View style={styles.modelViewer}>
            <ModelViewer />
        </View>


        <View style={styles.dataList}>
          <Text style={styles.boxText}>Daten zu {flight.title}</Text>
          <FlatList
            data={[{ key: 'Flug-ID: ' + flight.id }, { key: 'Datum: ' + flight.title.split(' - ')[1] }]}
            renderItem={({ item }) => (
              <View style={styles.flightItem}>
                <Text style={styles.flightText}>{item.key}</Text>
              </View>
            )}
          />
        </View>
      </View>

      <View style={styles.bottomBox}>
        <Text style={styles.boxText}>[ Weitere Informationen zu {flight.title} ]</Text>
      </View>
      <View style={styles.bottomBox}>
        <Text style={styles.boxText}>[ Weitere Informationen zu {flight.title} ]</Text>
      </View>
    </ScrollView>
  );
};


const styles = StyleSheet.create({
  container: {
    padding: 20,
    backgroundColor: '#212121',
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    color: '#fff',
    marginBottom: 20,
    textAlign: 'center',
  },
  videoBox: {
    borderWidth: 2,
    borderColor: 'red',
    borderRadius: 8,
    height: 200,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#2c2c2c',
    marginBottom: 20,
  },
  row: {
    flexDirection: 'row',
    gap: 10,
    marginBottom: 20,
  },
  modelViewer: {
    flex: 1,
    height: 300,
    backgroundColor: '#444',
    borderRadius: 8,
    justifyContent: 'center',
    alignItems: 'center',
  },
  dataList: {
    flex: 1,
    height: 300,
    borderWidth: 2,
    borderColor: 'red',
    borderRadius: 8,
    padding: 10,
    backgroundColor: '#2c2c2c',
  },
  flightItem: {
    padding: 10,
    borderBottomWidth: 1,
    borderBottomColor: '#555',
  },
  flightText: {
    color: '#fff',
    fontSize: 14,
  },
  video: {
  width: '100%',
  height: '100%',
  borderRadius: 8,
},

  bottomBox: {
  borderWidth: 2,
  borderColor: 'red',
  borderRadius: 8,
  padding: 20,
  backgroundColor: '#2c2c2c',
  justifyContent: 'center',
  alignItems: 'center',
  marginBottom: 20,  // <-- hier Abstand nach unten
},
  boxText: {
    color: '#fff',
  },
});

export default FlightMonitor;
