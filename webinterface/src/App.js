import React from "react";
import "./App.scss";
import Message from "./screen/Message";
import Setpoint from "./screen/Setpoint";

class App extends React.Component {
  render() {
    return (
      <div className="App">
        <Setpoint/>
      </div>
    );
  }
}

export default App;
