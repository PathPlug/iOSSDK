#
# Be sure to run `pod lib lint PathPlug.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "PathPlug"
  s.version          = "1.1.0"
  s.summary          = "iOS SDK to use PathPlug interactions."
  s.description      = <<-DESC
                      PathPlug iOS SDK allows you to login and access your interactions. You can enable different interactions as well as get raw beacon data to build beyond our platform. Works with any iBeacon devices in the market. Supports iOS7 and up.
                       DESC
  s.homepage         = "https://github.com/PathPlug/iOSSDK"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "Berk Taner" => "berk@pathplug.com" }
  s.source           = { :git => "https://github.com/PathPlug/iOSSDK.git", :tag => s.version.to_s }
   s.social_media_url = 'https://twitter.com/pathplug'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/PathPlugSDK.framework'
  s.resource_bundles = {
    'PathPlug' => ['Pod/Assets/*.png']
  }

   s.public_header_files = 'Pod/Headers/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end