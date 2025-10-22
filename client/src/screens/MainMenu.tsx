// src/screens/MainMenu.tsx
import React from 'react';
import { View, Text, TouchableOpacity, StyleSheet } from 'react-native';

const MainMenu: React.FC = () => {
  return (
    <View style={styles.container}>

      {/* Obere Box mit Main Menu, vertikal & horizontal zentriert */}
      <View style={styles.titleBox}>
        <Text style={styles.title}>Flight Controller</Text>
      </View>

      {/* Untere Box mit den Menüoptionen, Optionen vertikal und horizontal zentriert */}
      <View style={styles.menuBox}>
        <TouchableOpacity style={styles.menuButton}>
          <Text style={styles.menuText}>Flüge ansehen</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.menuButton}>
          <Text style={styles.menuText}>Designs ansehen</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.menuButton}>
          <Text style={styles.menuText}>Design registrieren</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.menuButton}>
          <Text style={styles.menuText}>Einstellungen</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.menuButtonRed}>
          <Text style={styles.menuText}>Flug starten</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
};



const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#212121',
    paddingHorizontal: 20,
    justifyContent: 'flex-start',
    alignItems: 'center',
    paddingTop: 50,
  },
  titleBox: {
    width: '100%',
    height: 100,               // Höhe definieren
    marginBottom: 30,
    justifyContent: 'center',  // vertikal zentrieren
    alignItems: 'center',      // horizontal zentrieren
  },
  title: {
    fontSize: 32,
    fontWeight: 'bold',
    color: 'white',
  },
  menuBox: {
    width: '100%',
    borderRadius: 10,
    paddingVertical: 20,
    paddingHorizontal: 15,
    
    justifyContent: 'center',
    alignItems: 'center',

    flexGrow: 1,
  },
  menuButton: {
    width: '80%',
    backgroundColor: '#444',
    paddingVertical: 15,
    borderRadius: 8,
    marginBottom: 15,
  },
  menuButtonRed: {
    width: '80%',
    backgroundColor: '#b43636ff',
    paddingVertical: 15,
    borderRadius: 8,
    marginBottom: 15,
  },
  menuText: {
    color: 'white',
    fontSize: 18,
    textAlign: 'center',
  },
});

export default MainMenu;
