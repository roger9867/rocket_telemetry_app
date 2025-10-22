// src/screens/LoginScreen.tsx

import React from 'react';
import { View, Text, StyleSheet, TextInput, TouchableOpacity } from 'react-native';
import { NativeStackScreenProps } from '@react-navigation/native-stack';

type RootStackParamList = {
  Login: undefined;
  MainMenu: undefined;
};

type Props = NativeStackScreenProps<RootStackParamList, 'Login'>;

const LoginScreen: React.FC<Props> = ({ navigation }) => {
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Login</Text>
      <TextInput
        placeholder="Username"
        placeholderTextColor="#ccc"
        style={styles.input}
      />
      <TextInput
        placeholder="Password"
        placeholderTextColor="#ccc"
        secureTextEntry
        style={styles.input}
      />
      <TouchableOpacity 
        style={styles.button}
        onPress={() => navigation.replace('MainMenu')} // ersetzt den Login-Screen mit MainMenu
      >
        <Text style={styles.buttonText}>Login</Text>
      </TouchableOpacity>
    </View>
  );
};


const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#212121',
    padding: 20,
    justifyContent: 'center',
  },
  title: {
    fontSize: 32,
    fontWeight: 'bold',
    color: 'white',
    marginBottom: 40,
    textAlign: 'center',
  },
  input: {
    backgroundColor: '#333',
    color: 'white',
    paddingHorizontal: 15,
    paddingVertical: 12,
    borderRadius: 8,
    marginBottom: 20,
  },
  button: {
    backgroundColor: '#444',
    paddingVertical: 15,
    borderRadius: 8,
  },
  buttonText: {
    color: 'white',
    fontSize: 18,
    textAlign: 'center',
  },
});

export default LoginScreen;
