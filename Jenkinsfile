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
			bat './Source/Test/try.cmd'
            bat(returnStatus: true, script: 'cd')
            bat(returnStatus: true, script: 'call Source/Test/try.cmd')
           }
        }
        stage('Build') {
          steps {
            echo 'Build'
            bat(returnStatus: true, script: 'rem call ./Stage/Building/Build.cmd')
          }
        }
      }
    }
  }
}