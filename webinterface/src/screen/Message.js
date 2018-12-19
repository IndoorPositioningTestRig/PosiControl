import React from "react";
import Dropdown from "../components/Dropdown/Dropdown";
import "./Message.scss";
import {TYPE} from "../constants/Message";
import {BaseUrl} from "../constants/Api";

export default class Message extends React.Component{
  constructor(props) {
    super(props);

    this.state = {
      message: {
        target: null,
        messageType: null,
        data: "",
      }
    };

    this.handleConfirmClick = this.handleConfirmClick.bind(this);
  }

  handleValue(field, value) {
    const {message} = this.state;
    message[field] = value;
    this.setState({message});
  }

  handleConfirmClick() {
    const {message} = this.state;

    if (message.target === null) {
      alert("Target missing!");
      return;
    }
    if (message.messageType === null) {
      alert("Type missing");
      return;
    }
    const messageType = TYPE[message.messageType];
    fetch(`${BaseUrl}/msg/${message.target}/${messageType}/`, {
      method: "post",
      body: message.data,
      mode: "no-cors",
    });
  }

  render() {
    const {message} = this.state;

    return (
      <div className={"screen-message"}>
        <div className={"header"}>Send a message</div>
        <div className={"body"}>
          {/* Target */}
          <div className={"field"}>
            <div className={"name"}>target:</div>
            <div className={"value"}>
              <Dropdown
                onSelected={(value) => this.handleValue("target", value)}
                value={message.target}
                options={[0, 1, 2, 3, 4, 5, 6, 7, 8]}
              />
            </div>
          </div>
          {/* Message type */}
          <div className={"field"}>
            <div className={"name"}>type:</div>
            <div className={"value"}>
              <Dropdown
                onSelected={(value) => this.handleValue("messageType", value)}
                value={message.messageType}
                options={["command", "request", "response"]}
              />
            </div>
          </div>
          {/* Content */}
          <div className={"field"}>
            <div className={"name"}>data:</div>
            <div className={"value"}>
              <div className={"text-wrapper"}>
                <textarea
                  rows={"4"}
                  onChange={(e) => this.handleValue("data", e.target.value)}
                  value={message.data}
                />
              </div>
            </div>
          </div>
          {/* Confirm */}
          <div
            onClick={this.handleConfirmClick}
            className={"confirm-button"}
          >
          Send
          </div>
        </div>
      </div>
    );
  }
}
