#ifndef ECS_STATUS_H
#define ECS_STATUS_H

class Status {
 private:
  // основное меню
  bool newGame_ = false;
  bool settingGameOnOff_ = false;
  bool endGame_ = false;

 public:
  bool isNewGame() const {
    return newGame_;
  }
  void setNewGame(bool newGame) {
    newGame_ = newGame;
  }
  bool isSettingGameOnOff() const {
    return settingGameOnOff_;
  }
  void setSettingGameOnOff(bool settingGameOnOff) {
    settingGameOnOff_ = settingGameOnOff;
  }
  bool isEndGame() const {
    return endGame_;
  }
  void setEndGame(bool endGame) {
    endGame_ = endGame;
  }
};

#endif  // ECS_STATUS_H
