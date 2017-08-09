#
# Be sure to run `pod lib lint SGVSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'SGVSDK'
  s.version          = '2.2.1'
  s.summary          = 'SGVSDK for SGV'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
 SGV SDK descriptionSGV SDK descriptionSGV SDK descriptionSGV SDK descriptionSGV SDK description
                       DESC

  s.homepage         = 'https://github.com/qiushuitian/SGVSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'qiushuitian1111' => 'qiushuitian1111@126.com' }
  s.source           = { :git => 'https://github.com/qiushuitian/SGVSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'SGVSDK/Classes/**/*'

  s.vendored_frameworks = 'SGVSDK/SGVSDK.framework'

  # s.resource_bundles = {
  #   'SGVSDK' => ['SGVSDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.dependency 'AFNetworking'
  s.dependency 'JSONModel'
  s.dependency 'FMDB'
  s.dependency 'MJExtension'
end
