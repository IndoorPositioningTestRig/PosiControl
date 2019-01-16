import React from "react";
import "./App.scss";
import Message from "./screen/Message";
import Setpoint from "./screen/Setpoint";
import Home from "./screen/Home";
import {Switch, Route} from "react-router-dom";

import TopBar from "./components/TopBar/TopBar";

class App extends React.Component {
  render() {

    return (
      <div className="App">
        <TopBar />
        <Switch>
          <Route path={"/message"} component={Message}/>
          <Route path={"/home"} component={Home}/>
          <Route path={"/"} component={Setpoint}/>
        </Switch>
      </div>
    );
  }
}

export default App;
