import React from 'react';
import { View, Text, StyleSheet, FlatList } from 'react-native';

const dummyDesigns = [
  { id: '1', name: 'Design Alpha' },
  { id: '2', name: 'Design Beta' },
  { id: '3', name: 'Design Gamma' },
  { id: '4', name: 'Design Delta' },
  { id: '5', name: 'Design Epsilon' },
  { id: '6', name: 'Design Zeta' },
  { id: '7', name: 'Design Eta' },
  { id: '8', name: 'Design Theta' },
  { id: '9', name: 'Design Iota' },
  { id: '10', name: 'Design Kappa' },
  { id: '11', name: 'Design Lambda' },
  { id: '12', name: 'Design Mu' },
  { id: '13', name: 'Design Nu' },
  { id: '14', name: 'Design Xi' },
];


const DesignViewList: React.FC = () => {
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Rocket Design List</Text>
      <FlatList
        data={dummyDesigns}
        keyExtractor={(item) => item.id}
        renderItem={({ item }) => (
          <View style={styles.designItem}>
            <Text style={styles.designText}>{item.name}</Text>
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
  designItem: {
    backgroundColor: '#333',
    padding: 15,
    borderRadius: 8,
    marginBottom: 10,
  },
  designText: {
    color: '#fff',
    fontSize: 16,
  },
});

export default DesignViewList;
