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
            bat(returnStatus: true, script: 'cd')
           }
        }
        stage('Build') {
          steps {
            echo 'Build'
            bat(returnStatus: true, script: 'rem ./Stages/Build/Build.cmd')
          }
        }
      }
    }
  }
}