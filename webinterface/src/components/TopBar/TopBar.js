import React from "react";
import "./TopBar.scss";
import {withRouter} from "react-router-dom";
import enhanceWithClickOutside from "react-click-outside";

class TopBar extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      menuOpen: false,
      navTarget: null,
    };

    this.handleClose = this.handleClose.bind(this);
    this.handleButtonClick = this.handleButtonClick.bind(this);
    this.handleNavClicked = this.handleNavClicked.bind(this);
  }

  handleButtonClick() {
    this.setState({menuOpen: !this.state.menuOpen});
  }

  handleClose() {
    this.setState({menuOpen: false});
  }

  handleNavClicked(nav) {
    this.props.history.push(nav);
    this.setState({menuOpen: false});
  }

  render() {
    return (
      <div className={"top-bar"}>
        <div onClick={this.handleButtonClick} className={"menu-button"}>
          <div className={"icon"}>
            <div className={"line"}/>
            <div className={"line"}/>
            <div className={"line"}/>
          </div>
        </div>
        {this.state.menuOpen &&
          <MenuClickOutside
            onOptionClick={this.handleNavClicked}
            onClickOutside={this.handleClose}
          />
        }
      </div>
    );
  }
}

export default withRouter(TopBar);

class Menu extends React.Component {
  handleClickOutside() {
    this.props.onClickOutside();
  }

  render() {
    return (
      <div className={"menu"}>
        <div
          className={"option"}
          onClick={() => this.props.onOptionClick("/")}
        >
          Setpoint
        </div>
        <div
          className={"option"}
          onClick={() => this.props.onOptionClick("message")}
        >
          Message
        </div>
      </div>
    );
  }
}

const MenuClickOutside = enhanceWithClickOutside(Menu);
