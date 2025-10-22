import React from 'react';
import { View, Text, StyleSheet, FlatList } from 'react-native';

const dummyFlights = [
  { id: '1', title: 'Flight A - 12.10.2025' },
  { id: '2', title: 'Flight B - 13.10.2025' },
  { id: '3', title: 'Flight C - 14.10.2025' },
  { id: '4', title: 'Flight D - 15.10.2025' },
  { id: '5', title: 'Flight E - 16.10.2025' },
  { id: '6', title: 'Flight F - 17.10.2025' },
  { id: '7', title: 'Flight G - 18.10.2025' },
  { id: '8', title: 'Flight H - 19.10.2025' },
  { id: '9', title: 'Flight I - 20.10.2025' },
  { id: '10', title: 'Flight J - 21.10.2025' },
  { id: '11', title: 'Flight K - 22.10.2025' },
  { id: '12', title: 'Flight L - 23.10.2025' },
  { id: '13', title: 'Flight M - 24.10.2025' },
  { id: '14', title: 'Flight N - 25.10.2025' },
];

const FlightViewList: React.FC = () => {
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Flüge</Text>
      <FlatList
        data={dummyFlights}
        keyExtractor={(item) => item.id}
        renderItem={({ item }) => (
          <View style={styles.flightItem}>
            <Text style={styles.flightText}>{item.title}</Text>
          </View>
        )}
        contentContainerStyle={styles.listContent}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#212121',
    paddingTop: 40,
    paddingHorizontal: 20,
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    color: '#fff',
    marginBottom: 20,
    textAlign: 'center',
  },
  listContent: {
    paddingBottom: 20,
  },
  flightItem: {
    backgroundColor: '#333',
    padding: 15,
    borderRadius: 8,
    marginBottom: 10,
  },
  flightText: {
    color: '#fff',
    fontSize: 16,
  },
});

export default FlightViewList;
