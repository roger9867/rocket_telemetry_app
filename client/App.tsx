import React from 'react';
import { StatusBar, useColorScheme } from 'react-native';
import { SafeAreaProvider } from 'react-native-safe-area-context';

import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';

import LoginScreen from './src/screens/LoginScreen';
import MainMenu from './src/screens/MainMenu';
import FlightViewList from './src/screens/FlightViewList';
import DesignViewList from './src/screens/DesignViewList';

import { RootStackParamList } from './src/navigation/types';  // Import des Typs

const Stack = createNativeStackNavigator<RootStackParamList>();

const App = () => {
  const isDarkMode = useColorScheme() === 'dark';

  return (
    <SafeAreaProvider>
      <StatusBar barStyle={isDarkMode ? 'light-content' : 'dark-content'} />
      <NavigationContainer>
        <Stack.Navigator
          initialRouteName="Login"
          screenOptions={{ headerShown: false }}
        >
          <Stack.Screen name="Login" component={LoginScreen} />
          <Stack.Screen name="MainMenu" component={MainMenu} />
          <Stack.Screen
            name="Flights"
            component={FlightViewList}
            options={{
              headerShown: true,
              title: 'Flüge ansehen',
              headerTintColor: '#fff',
              headerStyle: { backgroundColor: '#212121' },
              headerTitleAlign: 'center',
            }}
          />
          <Stack.Screen
            name="Designs"
            component={DesignViewList}
            options={{
              headerShown: true,
              title: 'Designs ansehen',
              headerTintColor: '#fff',
              headerStyle: { backgroundColor: '#212121' },
              headerTitleAlign: 'center',
            }}
          />
        </Stack.Navigator>
      </NavigationContainer>
    </SafeAreaProvider>
  );
};

export default App;
