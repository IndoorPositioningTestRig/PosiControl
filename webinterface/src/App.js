import React from "react";
import "./App.scss";
import Message from "./screen/Message";

class App extends React.Component {
  render() {
    return (
      <div className="App">
        <Message/>
      </div>
    );
  }
}

export default App;
