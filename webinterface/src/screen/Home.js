import React from "react";
import "./Home.scss";
import {BaseUrl} from "../constants/Api";

export default class Home extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      responses: [],
      homing: false,
    };

    this.handleHomeClicked = this.handleHomeClicked.bind(this);
  }

  async handleHomeClicked() {
    const {homing} = this.state;
    const responses = this.state.responses.slice();
    if (homing) return;

    this.setState({
      homing: true,
    });

    const response = await fetch(`${BaseUrl}/home/`, {
      method: "get",
    });

    const responseText = await response.text();
    responses.push(responseText);
    this.setState({
      homing: false,
      responses,
    });
  }

  renderResponses() {
    const {responses} = this.state;

    if (responses.length === 0) {
      return null;
    }

    return (
      <div>
        {responses.map((response, index) =>
          <div className={"result-row"}>
            <div className={"index"}>{index}:</div>
            <div>{response}</div>
          </div>)
        }
      </div>
    );
  }

  render() {
    const {homing} = this.state;

    return (
      <div className={"home"}>
        <button
          disabled={homing}
          onClick={this.handleHomeClicked}
        >
          HOME!
        </button>
        {homing &&
          <div>
            Homing in progress, please wait...
          </div>
        }
        {this.renderResponses()}
      </div>
    );
  }
}