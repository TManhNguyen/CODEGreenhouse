import { LightBulbIcon } from '@heroicons/react/outline';
import GenericToggle from './GenericToggle';

type Props = {
  enabled: boolean
  onClick: any
}

const LightToggle = ({
  enabled,
  onClick
}: Props) => {
  return (  
    <GenericToggle title="Light" isOn={enabled} onClick={onClick}>
      <LightBulbIcon className="h-9 w-9" />
    </GenericToggle>
  ) 
}

export default LightToggle