open Navigation;

open TabNavigator;

open BsReactNative;

let component = ReasonReact.statelessComponent("Feed");

module Styles = {
  open Style;
  let container =
    style([flex(1.), alignItems(Center), justifyContent(Center)]);
  let title = style([color(String("#000")), fontSize(Float(24.))]);
  let button = color =>
    style([
      flex(1.),
      justifyContent(Center),
      paddingHorizontal(Pt(20.)),
      maxHeight(Pt(40.)),
      marginTop(Pt(16.)),
      backgroundColor(String(color)),
      borderRadius(20.),
    ]);
  let buttonText = style([color(String("white"))]);
};

let make =
    (~navigation, ~stackNavigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <TabNavigator.Screen label="My Feed" navigation>
      <View style=Styles.container>
        <Text style=Styles.title>
          (ReasonReact.stringToElement("Feed"))
        </Text>
        <TouchableOpacity onPress=(_e => navigation.goTo(Config.Likes))>
          <View style=(Styles.button("#2180f7"))>
            <Text style=Styles.buttonText>
              (ReasonReact.stringToElement("Show likes"))
            </Text>
          </View>
        </TouchableOpacity>
        <TouchableOpacity onPress=(_e => stackNavigation.push(Config.Home))>
          <View style=(Styles.button("#ff2242"))>
            <Text style=Styles.buttonText>
              (ReasonReact.stringToElement("Take me home"))
            </Text>
          </View>
        </TouchableOpacity>
      </View>
    </TabNavigator.Screen>,
};