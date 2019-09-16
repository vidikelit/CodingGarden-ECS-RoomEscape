#ifndef ECS_STATUS_H
#define ECS_STATUS_H

class Status {
 private:
  // основное меню
  bool gameMenuStatus_ = true;
  bool newGame_ = false;
  bool loadGame_ = false;
  bool settingGame_ = false;
  bool settingGameOnOff_ = true;
  bool continueGame_ = false;
  bool endGame_ = false;

 public:
  bool isGameMenuStatus() const {
    return gameMenuStatus_;
  }
  void setGameMenuStatus(bool gameMenuStatus) {
    gameMenuStatus_ = gameMenuStatus;
  }
  bool isNewGame() const {
    return newGame_;
  }
  void setNewGame(bool newGame) {
    newGame_ = newGame;
  }
  bool isLoadGame() const {
    return loadGame_;
  }
  void setLoadGame(bool loadGame) {
    loadGame_ = loadGame;
  }
  bool isSettingGame() const {
    return settingGame_;
  }
  void setSettingGame(bool settingGame) {
    settingGame_ = settingGame;
  }
  bool isSettingGameOnOff() const {
    return settingGameOnOff_;
  }
  void setSettingGameOnOff(bool settingGameOnOff) {
    settingGameOnOff_ = settingGameOnOff;
  }
  bool isContinueGame() const {
    return continueGame_;
  }
  void setContinueGame(bool continueGame) {
    continueGame_ = continueGame;
  }
  bool isEndGame() const {
    return endGame_;
  }
  void setEndGame(bool endGame) {
    endGame_ = endGame;
  }
};

#endif  // ECS_STATUS_H
