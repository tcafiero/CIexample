pipeline {
  agent {
    node {
      label 'toolchain'
    }

  }
  stages {
    stage('Deploy') {
      parallel {
        stage('Deploy') {
          steps {
            echo 'Deploy...'
          }
        }
        stage('Test') {
          steps {
            echo 'Test...'
            bat(script: 'call "Source/TestCode/try.cmd"', returnStatus: true)
            bat(returnStatus: true, script: 'cd')
            bat(returnStatus: true, script: 'call Source/TestCode/try.cmd')
          }
        }
        stage('Build') {
          steps {
            echo 'Build'
            bat(returnStatus: true, script: 'call "./Stage/Building/Build.cmd"')
          }
        }
      }
    }
  }
}