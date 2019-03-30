pipeline {
  agent {
    node {
      label 'toolchain'
    }

  }
  stages {
    stage('Build') {
      when {
        branch 'develop'
      }
      steps {
        echo 'Build'
		timeout(time: 10, unit: 'MINUTES')
		{
			bat(script: '"C:\\CIexample\\workspace\\CIexample_develop\\Stages\\Building\\Build.cmd"', returnStatus: true)
		}
      }
    }
    stage('Test') {
      when {
        branch 'develop'
      }
      steps {
        echo 'Test'
		timeout(time: 10, unit: 'MINUTES')
		{
			bat(script: '"C:\\CIexample\\workspace\\CIexample_develop\\Stages\\Testing\\Test.cmd"', returnStatus: true)
		}
      }
    }
    stage('Stage') {
      when {
        branch 'stage'
      }
      steps {
        echo 'Stage'
        input(message: 'There is a candidate version, procede to release', ok: 'YES', id: 'tcafiero')
      }
    }
    stage('Release') {
      when {
        branch 'master'
      }
      steps {
        echo 'Master'
      }
    }
  }
}